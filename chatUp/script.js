(function(){

  var link = document.createElement("link");
  link.href = 'http://localhost:3101/embedCss';
  // link.href = 'http://pedago01c.univ-avignon.fr:3101/embedCss';
  link.rel = 'stylesheet';
  link.type = 'text/css';
  document.getElementsByTagName("head")[0].appendChild(link);

  var script = document.createElement("SCRIPT");
  script.src = 'https://cdnjs.cloudflare.com/ajax/libs/socket.io/2.1.1/socket.io.js';
  script.type = 'text/javascript';
  document.getElementsByTagName("head")[0].appendChild(script);

  window.chatUp = {
    conf: {},
    socket: null,
    load: function() {
      this.conf.elem = $('#'+this.conf.elem_id);
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
    init: function(elem_id, color) {
      console.log("Chat_up initialisation", elem_id, color);
      var conf = {};
      conf.elem_id = elem_id;
      if(typeof color !== "undefined") {
        conf.color = color;
      } else {
        conf.color = '#6c757d';
      }
      document.documentElement.style.setProperty('--chatup-color', conf.color);
      window.chatUp.conf = Object.assign(conf, window.chatUp.conf);
    }
  }

  if(typeof window.io !== 'function') {
    window.chatUp.socket = new WebSocket("ws://localhost:3101/chat");
    // window.chatUp.socket = new WebSocket("ws://pedago01c.univ-avignon.fr:3101/chat");
    document.getElementsByTagName("head")[0].appendChild(script);
    window.chatUp.userId = 'Toto'; //TODO: modifier ça en formulaire de saisie de nom
    window.chatUp.userId += '_' + Math.random().toString(36).substr(2, 5);  //Taken from https://gist.github.com/gordonbrander/2230317
  }

  //load jquery
  if(typeof window.jQuery !== 'function') {
    var script = document.createElement("SCRIPT");
    script.src = 'https://ajax.googleapis.com/ajax/libs/jquery/3.3.1/jquery.min.js';
    script.type = 'text/javascript';
    script.onload = function() {
      window.chatUp.load();

      $(window.chatUp.socket).on('message', function(e)
      {
        msg = JSON.parse(e.originalEvent.data);
        console.log("Message received: " + msg.message);
        $('#chatup-messages-list').append(
          '<div class="chatup-received-msg">' + msg.message + '</div>'
        );
      });

      $('#form-chatup').on('submit', function(e) {
        e.preventDefault();
        var $textarea = $('#textarea-chatup');
        console.log("textArea: ", $textarea, $textarea.val());
        if($textarea.val() == "")
          return;
        window.chatUp.socket.send(JSON.stringify({'message': $textarea.val(), 'id': window.chatUp.userId}));
        $('#chatup-messages-list').append(
          '<div class="chatup-user-msg">' + $textarea.val() + '</div>'
        );
        $textarea.val('');
      });

      $('#form-chatup-id').on('submit', function(e) {
        e.preventDefault();
        var $textarea = $('#textarea-chatup-id');
        var pseudo = $textarea.val();
        console.log("pseudo: ", $textarea, $textarea.val());
        if(pseudo == "")
          return;
        window.chatUp.userId = pseudo; //TODO: modifier ça en formulaire de saisie de nom
        window.chatUp.userId += '_' + Math.random().toString(36).substr(2, 5);  //Taken from https://gist.github.com/gordonbrander/2230317
        window.chatUp.socket.send(JSON.stringify({'id': window.chatUp.userId}));
        $('#form-chatup-id').addClass('hide');
        $('#mgs-need-id').addClass('hide');
        $('#form-chatup').removeClass('hide');
        $('#mgs-need-help').removeClass('hide');
        $('#chatup-pseudo').text(pseudo);
        $textarea.val('');
      });

      $('.hide-chatup-msg').on('click', function(e) {
        $chatup_messages = $('#chatup-messages-list');
        $chatup_messages.toggleClass('hidden-msg');
      });
    };
    document.getElementsByTagName("head")[0].appendChild(script);
  } else {
    window.chatUp.load();
  }

})();