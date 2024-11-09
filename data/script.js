
function updateLEDStatus() {
    fetch('/LEDstatus')
        .then(response => response.text())
        .then(status => {
            document.getElementById('led-status').innerText = status;
        });
}

function turnOnLED() {
    fetch('/on')
        .then(() => updateLEDStatus());
}

function turnOffLED() {
    fetch('/off')
        .then(() => updateLEDStatus());
}

document.addEventListener('DOMContentLoaded', (event) => {
    updateLEDStatus();
});