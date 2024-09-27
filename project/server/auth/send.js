const router = require("../config/router")

router.post("/", async (req, res) => {
    res.setHeader("Cache-Control", "no-cache, no-store, must-revalidate");
    res.setHeader("Pragma", "no-cache");
    res.setHeader("Expires", "0");

    const target = req.body.target;
    const message = req.body.message;
    const source = req.body.source;
    const timestamp = req.body.timestamp;

    const response = {
        message: message,
        status: "unread",
        timestamp: timestamp || Date.now(),
    }
    return res.json(response);
});

module.exports = router;