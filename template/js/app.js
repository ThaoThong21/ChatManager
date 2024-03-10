//get user from server in there
const userList = ["User1", "User2", "User3"];

//Display user
const userUl = document.getElementById("user-list");
userList.forEach(user => {
    const li = document.createElement("li");
    li.textContent = user;
    userUl.appendChild(li);
});

// send message
function sendMessage() {
    const messageInput = document.getElementById("message-input");
    const chatBox = document.getElementById("chat-box");

    //check input
    if (messageInput.value.trim() !== "") {
        const message = document.createElement("p");
        message.textContent = messageInput.value;
        chatBox.appendChild(message);
        messageInput.value = "";

        // auto scroll to end
        chatBox.scrollTop = chatBox.scrollHeight;
    }
}
