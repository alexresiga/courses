import json
import socket

HOST = "localhost"
PORT = 12345
END = "__end__"
BUFFER_SIZE = 4096

def getResponse(conn):
    message = ""
    while True:
        data = conn.recv(BUFFER_SIZE).decode("utf8")
        if not data:
            print("Error! Server disconnected!")
            return
        else:
            message += data
        if message.endswith(END):
            message = message[:len(message) - len(END)]
            break
    return message

def generateMessage(message):
    return message + END

def main():
    array1 = [1, 4, 6, 8, 9]
    array2 = [2, 3, 7, 5, 10]
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        s.connect((HOST, PORT))
        s.send(generateMessage(json.dumps([array1, array2])).encode("utf8"))
        print(getResponse(s))

main()
