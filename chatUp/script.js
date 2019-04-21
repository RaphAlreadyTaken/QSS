(function(){

  /**
   * Chargement du css associé au module
   */
  var link = document.createElement("link");
  link.href = 'http://localhost:3101/embedCss';
  // link.href = 'http://pedago01c.univ-avignon.fr:3101/embedCss';
  link.rel = 'stylesheet';
  link.type = 'text/css';
  document.getElementsByTagName("head")[0].appendChild(link);

  /**
   * Classe ChatUp: Module de chat
   */
  window.ChatUp = {
    conf: {},
    socket: null,
    /**
     * Fonction construisant l'outil de chat
     */
    load: function() {
      this.conf.elem = $('#'+this.conf.elemId);
      this.conf.elem.html(
        '<div id="chatup-form">'+
          '<div id="chatup-messages">'+
            '<div id="chatup-msg-header">'+
              '<div id="chatup-pseudo" class="chatup-pseudo"></div>'+
              '<div class="hide-chatup-msg">-</div>'+
            '</div>'+
            '<div id="chatup-messages-list">'+
              '<div id="mgs-need-id" class="chatup-received-msg">' + "Saisissez un pseudo" + '</div>'+
              '<div id="mgs-need-help" class="chatup-received-msg hide">' + "Besoin de mon aide?" + '</div>'+
            '</div>'+
          '</div>'+
          '<form id="form-chatup" class="hide">'+
            '<input id="textarea-chatup" rows="4" cols="50" type="text" name="comment" placeholder="besoin d\'aide?"></input>'+
            '<input id="chatup-send-msg" type="submit" value="send"></input>'+
          '</form>'+
          '<form id="form-chatup-id">'+
            '<input id="textarea-chatup-id" rows="4" cols="50" maxlength="15" type="text" name="comment" placeholder="Saisissez votre pseudo"></input>'+
            '<input id="chatup-send-msg-id" type="submit" value="send"></input>'+
          '</form>'+
        '</div>'
      );
    },
    /**
     * Fonction initialisant le module
     * param: elemId: emplacement où sera placé le module, dans la page html
     * param: color: Couleur personnalisable de l'outil
     */
    init: function(elemId, color) {
      console.log("Chat_up initialisation", elemId, color);
      var conf = {};
      conf.elemId = elemId;
      if(typeof color !== "undefined") {
        conf.color = color;
      } else {
        conf.color = '#6c757d';
      }
      document.documentElement.style.setProperty('--chatup-color', conf.color);
      window.ChatUp.conf = Object.assign(conf, window.ChatUp.conf);
    },
    /**
     * Fonction attribuant différents événements aux éléments constituant l'outil de chat
     */
    event: function() {
      var self = this;

      /**
       * Evénement de réception d'un message
       */
      $(self.socket).on('message', function(e)
      {
        msg = JSON.parse(e.originalEvent.data);
        console.log("Message received: " + msg.message);
        $('#chatup-messages-list').append(
          '<div class="chatup-received-msg">' + msg.message + '</div>'
        );
      });

      /**
       * Evénement d'envoi de message
       */
      $('#form-chatup').on('submit', function(e) {
        e.preventDefault();
        var $textArea = $('#textarea-chatup');
        console.log("textArea: ", $textArea, $textArea.val());
        if($textArea.val() == "")
          return;
        self.socket.send(JSON.stringify({'message': $textArea.val(), 'id': window.ChatUp.userId}));
        $('#chatup-messages-list').append(
          '<div class="chatup-user-msg">' + $textArea.val() + '</div>'
        );
        $textArea.val('');
      });

      /**
       * Evénement d'envoi de l'identifiant de l'utilisateur
       */
      $('#form-chatup-id').on('submit', function(e) {
        e.preventDefault();
        var $textArea = $('#textarea-chatup-id');
        var pseudo = $textArea.val();
        console.log("pseudo: ", $textArea, $textArea.val());
        if(pseudo == "")
          return;
        self.userId = pseudo;
        self.userId += '_' + Math.random().toString(36).substr(2, 5);  //Taken from https://gist.github.com/gordonbrander/2230317
        self.socket.send(JSON.stringify({'id': window.ChatUp.userId}));
        $('#form-chatup-id').addClass('hide');
        $('#mgs-need-id').addClass('hide');
        $('#form-chatup').removeClass('hide');
        $('#mgs-need-help').removeClass('hide');
        $('#chatup-pseudo').text(pseudo);
        $textArea.val('');
      });

      /**
       * Evénement de click pour cacher le chat
       */
      $('.hide-chatup-msg').on('click', function(e) {
        $chatupMessages = $('#chatup-messages-list');
        $chatupMessages.toggleClass('hidden-msg');
      });
    }
  }

  /**
   * Attribution du websocket
   */
  if(typeof window.io !== 'function') {
    window.ChatUp.socket = new WebSocket("ws://localhost:3101/chat");
    // window.ChatUp.socket = new WebSocket("ws://pedago01c.univ-avignon.fr:3101/chat");
    window.ChatUp.userId = 'Toto'; //TODO: modifier ça en formulaire de saisie de nom
    window.ChatUp.userId += '_' + Math.random().toString(36).substr(2, 5);  //Taken from https://gist.github.com/gordonbrander/2230317
  }

  //load jquery
  if(typeof window.jQuery !== 'function') {
    var script = document.createElement("SCRIPT");
    script.src = 'https://ajax.googleapis.com/ajax/libs/jquery/3.3.1/jquery.min.js';
    script.type = 'text/javascript';

    /**
     * Fonction de callback, charge le module et charge ses événements une fois que jQuery est importé
     */
    script.onload = function() {
      window.ChatUp.load();
      window.ChatUp.event();
    };
    document.getElementsByTagName("head")[0].appendChild(script);
  } else {
    window.ChatUp.load();
    window.ChatUp.event();
  }

})();