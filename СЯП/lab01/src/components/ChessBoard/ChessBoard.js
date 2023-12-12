import './ChessBoard.css';


const LETTERS = ["a", "b", "c", "d", "e", "f", "g", "h"];
const DIGITS = ["8", "7", "6", "5", "4", "3", "2", "1"];


function ChessBoard() {
    return (
        <div className="chess-board-wrapper">
            <div className="chess-board">
                <LettersRow />
                {DIGITS.map((digit, i) => <BoardRow key={i} digit={digit} />)}
                <LettersRow />
            </div>
        </div>
    );
}


function LettersRow() {
    return (
        <div className="row">
            <TextCell text="" />
            {LETTERS.map((letter, i) => <TextCell key={i} text={letter} />)}
            <TextCell text="" />
        </div>
    );
}


function BoardRow(props) {
    const colors = {false: "black", true: "white"}
    let currentColor = (+props.digit % 2 == 0)
    let cells = [];
    for (let i = 0; i < DIGITS.length; i++) {
        cells.push(<ColorCell key={i} color={colors[currentColor]} />);
        currentColor = !currentColor;
    }

    return (
        <div className="row">
            <TextCell text={props.digit} />
            {cells}
            <TextCell text={props.digit} />
        </div>
    );
}


function TextCell(props) {
    return (
        <div className="cell text">
            {props.text}
        </div>
    );
}


function ColorCell(props) {
    const classes = `cell ${props.color}`;
    return (
        <div className={classes}></div>
    );
}


export default ChessBoard;
