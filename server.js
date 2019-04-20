/******** Chargement des Middleware
*
********/
const express = require('express'); //Express.js
const pgClient = require('pg');		//BD PGSQL
const sha1 = require('sha1');	//Crytage des mdp
const session = require('express-session');	//Gestion des sessions
const MongoDBStore = require('connect-mongodb-session')(session);	//MongoDB for session
const MongoClient = require('mongodb').MongoClient; //MongoDB for other
const mongodb = require('mongodb');
const path = require('path');
const bodyParser = require('body-parser');

/******** Declaration des variables
*
********/
const app = express(); // expressJS

const dsnMongoDB = "mongodb://127.0.0.1:27017/db";

app.use(session({
	//	Initialisation de la session
	secret: 'ma phrase secrete',
	saveUninitialized: false,
	resave: false,
	store: new MongoDBStore({
		uri: "mongodb://127.0.0.1:27017/db",
		collection: 'mySession_3101',
		touchAfter: 24 * 3600
	}),
	cookie: {
		maxAge: 24 * 3600 * 1000
	}
}));

app.use(bodyParser.json());


/******** Configuration du serveur NodeJS - Port : 3101
*
********/
var server = app.listen(3101, function() {
	console.log('listening on 3101');
});

/*******
*	Configuration du webSocket
*******/

	/// Former version ///
// var io = require('socket.io').listen(server); // définit le middleware socket.io et le serveur avec lequel la connexion full-duplex doit être établie

// io.on('connection', function (socket) { // ouverture de la connexion full-duplex disponible dans le paramètre socket
// 	console.log('connexion socket.io');

// 	socket.on("notification client", function (data) {
// 		console.log(data);
// 	});

// 	socket.on("chatMessage", function(message)
// 	{
// 		console.log('Message reçu : ' + message);
// 		socket.broadcast.emit("Message: " + message);
// 	})
// });

const sock = require('ws').Server;
const ws = new sock({server});

clients = {};		//Web clients
clientsHlp = {};	//Helper clients (app)

ws.on('connection', wsock =>
{
	console.log("Client connected");

	wsock.on('message', message =>
	{
		console.log("%o", message);
		msg = JSON.parse(message);

		if (msg.message != null && msg.message.length > 0)
		{
			console.log("Message received: " + msg.message);
		}

		//Web client
		if (msg.id != null && msg.id.length > 0)
		{
			//New web client
			if (!(msg.id in clients))
			{
				clients[msg.id] = wsock;
				clients[msg.id].helper = null;
				console.log("Adding new web client (" + Object.keys(clients).length + " total)");
				return;
			}

			//Send message to first available helper client
			helper = clients[msg.id].helper;

			if (helper == null)	//No helper associated with client
			{
				for (var key in clientsHlp)
				{
					if (clientsHlp[key].target == null)
					{
						clientsHlp[key].target = msg.id;	//Give helper a client
						clientsHlp[key].send(message);
						console.log("Message transferred to " + key);
						return;
					}
				}

				msg.message = "No helper available. Please try again in a few minutes.";
				wsock.send(JSON.stringify(msg));
			}
			else	//Helper already associated with client
			{
				clientsHlp[helper].send(message);
				return;
			}

		}

		//Helper client
		else if (msg.idHlp != null && msg.idHlp.length > 0)
		{
			//New helper client
			if (!(msg.idHlp in clientsHlp))
			{
				clientsHlp[msg.idHlp] = wsock;
				clientsHlp[msg.idHlp].target = null;
				console.log("Adding new helper client (" + Object.keys(clientsHlp).length + " total)");
				return;
			}

			//Send message to designated web client
			target = clientsHlp[msg.idHlp].target;
			clients[target].helper = msg.idHlp;		//Give client a helper
			clients[target].send(message);
			console.log("Message transferred to " + target);
		}

		//Who this
		else
		{
			return;
		}
	});
});

/******** Gestion des URI
*
********/
app.get('/', function(req, res) {
	console.log('load page /');
	res.send('Connected');
});

app.get('/demo', function(req, res) {
	console.log('load page /demo');
	res.sendFile(path.join(__dirname + '/demo/ex.html'));
});

app.get('/embed', function(req, res) {
	console.log('embed file');
	res.sendFile(path.join(__dirname + '/chatUp/script.js'));
});

app.get('/embedCss', function(req, res) {
	console.log('embed file');
	res.sendFile(path.join(__dirname + '/chatUp/script.css'));
});

