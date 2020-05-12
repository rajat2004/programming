var play_board = ["", "", "", "", "", "", "", "", ""];

const myHeading = document.querySelector('h1');
myHeading.textContent = "Hello World!";

var board_container = document.querySelector(".play-area");
var logo = document.getElementById("img");


function hideImg() {
    // document.body.style.background = 'none';
    logo.style.display='none';
}

function displayImg() {
    logo.style.display='block';
}

// var body = document.body;
// body.style.background='none';

function render_board() {
    board_container.innerHTML = "";
    for(i=0; i<9; i++) {
        board_container.innerHTML += `<div id="block_${i}" class="block" onclick="addPlayerMove(${i})"> ${play_board[i]} </div>`;
    }
}

render_board();
setTimeout(hideImg, 2*1000);
