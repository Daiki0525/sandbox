<?php
    header('Content-type:text/html; charset=UTF-8');
   
    $interval = 2000;
?>

<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="ja" lang="ja">
<head>
<meta name="robots" content="noindex,nofollow" />
<script type="text/javascript" src="http://ajax.googleapis.com/ajax/libs/jquery/1.3.2/jquery.js"></script>
<script type="text/javascript">
var timer = null;
function start_tail(){
    if (timer){
        clearInterval(timer);
    }
    $('#status').html('running...');
    timer = setInterval(run,<?php echo $interval ?>);
}
 
function run(){
    $('#console').load('./console.php?load=1&m=' + new Date().getTime());
}
 
function stop(){
    clearInterval(timer);
    $('#status').empty();
}
</script>
<style type="text/css">
#console {
    width:800px;
    height:500px;
    overflow:scroll;
    border:1px solid #999999;
    font-size:12px;
    font-family:consolas;
}
</style>
</head>
<body>
<input type="button" onclick="start_tail()" value="TAIL"> <input type="button" onclick="stop()" value="STOP"> <span id="status"></span><br />
<pre id="console"></pre>
</body>
</html>
