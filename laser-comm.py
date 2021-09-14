import socket

LASER_IP = "169.254.12.13"
LASER_PORT = 5000

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as sk:
    sk.bind((LASER_IP, LASER_PORT))
    sk.listen()
    laser, adr = sk.accept()
    with laser:
        print("Connected: ", adr)
        while True:
            msg = raw_input("Enter laser command: ")
            if(msg == "x"):
                print("Exiting...")
                exit(1)
            con.sendall(msg)
            print("Laser response: ", conn.recv(1024))
