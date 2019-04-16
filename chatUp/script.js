(function(){

  var link = document.createElement("link");
  link.href = 'http://pedago01c.univ-avignon.fr:3101/embedCss';
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
            '<div class="hide-chatup-msg">-</div>'+
            '<div class="chatup-recived-msg">' + "Besoin de mon aide?" + '</div>'+
          '</div>'+
          '<form id="form-chatup">'+
            '<input id="textarea-chatup" rows="4" cols="50" type="text" name="comment" placeholder="besoin d\'aide?"></input>'+
            '<input id="chatup-send-msg" type="submit" value="send"></input>'+
          '</form>'+
        '</div>'
      );
    },
    init: function(elem_id) {
      console.log("Bonjour, je suis chez toi ;)", elem_id);
      var conf = {};
      conf.elem_id = elem_id;
      window.chatUp.conf = Object.assign(conf, window.chatUp.conf);
    }
  }

  if(typeof window.io !== 'function') {
    var script = document.createElement("SCRIPT");
    script.src = 'https://cdnjs.cloudflare.com/ajax/libs/socket.io/2.1.1/socket.io.js';
    script.type = 'text/javascript';
    script.onload = function() {
      window.chatUp.socket = io.connect('http://pedago01c.univ-avignon.fr:3101');
    };
    document.getElementsByTagName("head")[0].appendChild(script);
  }

  //load jquery
  if(typeof window.jQuery !== 'function') {
    var script = document.createElement("SCRIPT");
    script.src = 'https://ajax.googleapis.com/ajax/libs/jquery/3.3.1/jquery.min.js';
    script.type = 'text/javascript';
    script.onload = function() {
      window.chatUp.load();
      $('#form-chatup').on('submit', function(e) {
        e.preventDefault();
        var $textarea = $('#textarea-chatup');
        console.log("textArea: ", $textarea, $textarea.val());
        if($textarea.val() == "")
          return;
        window.chatUp.socket.emit('chatMessage', $textarea.val());
        $('#chatup-messages').append(
          '<div class="chatup-user-msg">' + $textarea.val() + '</div>'
        );
        $textarea.val('');
      });

      $('.hide-chatup-msg').on('click', function(e) {
        $chatup_messages = $('#chatup-messages');
        $chatup_messages.toggleClass('hidden-msg');
      });
    };
    document.getElementsByTagName("head")[0].appendChild(script);
  } else {
    window.chatUp.load();
  }

})();