import json
import os
import socket

HOST = ""
PORT = 12345
END = "__end__"
BUFFER_SIZE = 4096

def generateResponse(message):
    array1, array2 = tuple(json.loads(message))
    return json.dumps(sorted(array1 + array2)) + END

def handleClient(conn):
    message = ""
    while True:
        data = conn.recv(BUFFER_SIZE).decode("utf8")
        if not data:
            print("Error! Client disconnected!")
            return
        else:
            message += data
        if message.endswith(END):
            message = message[:len(message) - len(END)]
            break
    conn.send(generateResponse(message).encode("utf8"))

def main():
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        s.bind((HOST, PORT))
        s.listen()
        while True:
            conn, addr = s.accept()
            if os.fork() == 0:
                handleClient(conn)
                break

main()
