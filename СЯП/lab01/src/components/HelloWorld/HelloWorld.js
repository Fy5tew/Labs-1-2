function HelloWorld() {
    return (
        <div>
            <h1>Hello, world!</h1>
            <CurrentDate />
        </div>
    );
}


function CurrentDate() {
    return (
        <p>Current date: {new Date().toLocaleString()}</p>
    );
}


export default HelloWorld;
