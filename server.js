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
var server=app.listen(3101, function() {
	console.log('listening on 3101');
});

/*******
*	Configuration du webSocket
*******/
var io = require('socket.io').listen(server); // définit le middleware socket.io et le serveur avec lequel la connexion full-duplex doit être établie

io.on('connection', function (socket) { // ouverture de la connexion full-duplex disponible dans le paramètre socket
	console.log('connexion socket.oi');

	socket.on("notification client", function (data) {
		console.log(data);
	});

	socket.on("chatMessage", function(message)
	{
		console.log('Message reçu : ' + message);
	})
});

/******** Gestion des URI
*
********/
app.get('/', function(req, res) {
	console.log('load page /');
	res.sendFile(path.join(__dirname + '/index.html'));
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

