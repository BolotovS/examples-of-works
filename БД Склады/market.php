<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
            <title>Пример блочной верстки</title>
<link rel="stylesheet" type="text/css" href="style.css" />
</head>
 
<body>
 
<div id="container">
	<div id="header">
	<h2> Магазины</h2>
	</div>
		 	 
	<div id="menu">
	<h2>Таблицы:</h2>
	<p><a href="deliv.php" id ="knopka">Завоз</a></p>
	<br>
	<p><a href="sklad.php" id ="knopka">Склады</a></p>
	<br>
	<p><a href="product.php".html" id ="knopka">Продукты</a></p>
	<br>
	<p><a href="car.php".html" id ="knopka">Машины</a></p>
	<br>
	<p><a href="market.php".html" id ="knopka">Магазины</a></p>
	<br>
	<p><a href="poligon.php".html" id ="knopka">Полигон</a></p>
	<br>
	</div>
		 
<div id="content">
	<STYLE>
	TABLE,TH,TD {border:1px solid black}
	TH,TD{width:100px}
	TH{height:30px}
	</STYLE>
	<?php
	$con_str=mysql_connect('localhost', 'root', '', 'bd_sklad');
	if(mysql_connect('localhost','root')){
		echo "Hello!!!";
 }
  mysql_select_db('bd_sklad',$con_str);
 
 
$result=mysql_query("SELECT market.id, market.id_sclad, car.mark, product.title FROM `market`\n"
    . "inner join car on market.id_car = car.id\n"
    . "inner join product on market.id_product = product.id");
echo "<table border=1px>";
echo"<tr><th>Номер</th>
<th>склад</th>
<th>Машина</th>
<th>Продукты</th><td><a href=Add.php>Добавить</a></td><td><a href=del.php>Удалить</a></td></tr>";
  while($row = mysql_fetch_array($result)){
    $ids=$row['id'];
    $storage=$row['id_sclad'];
    $product=$row['mark'];
	$car=$row['title'];
 
    echo 
"<tr><td>",$ids,
"</td><td>",$storage,
"</td><td>",$product,
"</td><td>",$car,
"</td></tr>";

}
echo "</table>";
 mysql_close();
?>
</div>
		 
<div id="clear">
		 
	</div>
							   
</div>
		 
</body>
</html>