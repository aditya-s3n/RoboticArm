import serial
from flask import Flask
from flask import request  

serialPort = serial.Serial('/dev/ttyACM0', 9600, timeout=1.0)

serialPort.reset_input_buffer()
serialPort.reset_output_buffer()

app = Flask(__name__)  

@app.route('/', methods=['POST'])
def index():
    if request.method == "POST":
        data = request.form
        name = data["name"]
        preset_name = data["preset"]

        serialPort.write(name)
        serialPort.write(preset_name)


if __name__ == "__main__":
    app.run()