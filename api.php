<?php
// Ricevi il JSON
$json_data = file_get_contents("php://input");
$data = json_decode($json_data, true);

$host = "localhost";
$user = "root";
$password = "";
$db = "danmuso";

$conn = new mysqli($host, $user, $password, $db);

if ($data) {
    $query = "INSERT INTO lolin_sensore (NomeScheda, Temperatura, Umidita) VALUES ('" . $data['NomeScheda'] . "', " . $data['Temperatura'] . ", " . $data['Umidita'] . ")";
    $conn->query($query);
}

$query_select = "SELECT * FROM lolin_sensore";
$result_select = $conn->query($query_select);

if (!$result_select) {
    die("Query failed: " . $conn->error);
}

// Costruisci un array associativo con i dati
$data_array = array();
while ($row = $result_select->fetch_assoc()) {
    $data_array[] = $row;
}

$conn->close();

// Converti l'array associativo in formato JSON
$json_response = json_encode($data_array);

// Restituisci solo il JSON di risposta
header('Content-Type: application/json');
echo $json_response;
?>