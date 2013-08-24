<html>
<body>
<?php  

// [Hash] =md5( [LOGIN]+[PASSWORT]+[LVNR]+[BEZEICHNUNG]+[VORNAME]+[NACHNAME]+[STRASSE]+[PLZ]+[ORT]+[EMAIL]+[HOCHSCHULE]+[STUDIENFACH]+[ABSCHLUSS]+Salt)
// 
    echo "Attribute, die von der vhb übertragen werden: <em>(mit SALT aus vhb-DB)!)</em><br>";
    print_r($_POST). PHP_EOL; // Ausgabe aller POST-Elemente 
    echo "<br /><br /> vhb-Hash:".$_POST['HASH']."<br /><br />" ;
    
    // dieser Saltwert muß mit dem in der vhb-DB übereinstimmen
    $salt="testSALTweRt";

    $attribute = $_POST['LOGIN'].$_POST['PASSWORT'].$_POST['LVNR'].$_POST['BEZEICHNUNG'].$_POST['VORNAME'].$_POST['NACHNAME'].$_POST['STRASSE'].$_POST['PLZ'].$_POST['ORT'].$_POST['EMAIL'].$_POST['HOCHSCHULE'].$_POST['STUDIENFACH'].$_POST['ABSCHLUSS'].$salt; 
    echo "Attribute, die der LMS Anbieter zum Hash verwendet: <em>(Hier SALT aus Quellcode!)</em><br>".$attribute."<br/><br />";
    
    $hash = md5($attribute);
    echo "LMS-Hash:".$hash."<br /><br /><br />";
    if ($hash == $_POST['HASH']){
    echo "<strong>Hashes identisch!</strong>";}
    else {echo "Hashes stimmen <strong>nicht</strong> überein."."<br>";
          echo "Ist der Saltwert $salt im formularcheck.php identisch zu dem in der vhb-DB?"."<br>";
          echo "Gibt es evtl. Probleme mit Umlauten?"."<br>";
           }  
    
    
?>
</body></html>