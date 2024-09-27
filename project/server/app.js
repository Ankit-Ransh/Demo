const server = require("./config/middleware");

const sendNotification = require("./auth/send");
server.use('/send', sendNotification);

server.get("/", (req, res) => {
    res.send("Welcome to the Notification API");
});

server.listen(8080, () => {
    console.log("Server Connected");
});