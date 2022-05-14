// Express
import express from "express";
const server = express();

// Serve static files from /public
server.use(express.static("public"));

// Start server
server.listen(2222, () => console.log("Server running on port 2222!"));
