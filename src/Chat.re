[@react.component]
let make = (~name, ~asset, ~state) => {
  let chat =
    List.find(
      (c: State.chat) => c.name == "Azure",
      State.Script.list_chats(state),
    );
  let messages = State.Script.chat_messages(state, chat);

  let message_items =
    messages
    |> List.map((m: State.chat_message) =>
         switch (m) {
         | State.Inbound(from, text) =>
           <div className="chat-message chat-message--incoming">
             {React.string(text)}
           </div>
         | State.Outbound(text) =>
           <div className="chat-message"> {React.string(text)} </div>
         }
       )
    |> Array.of_list;

  let main = <div className="chat"> {React.array(message_items)} </div>;
  let side = <img className="chat-sprite" src={asset("azure.png")} />;

  <Window title={"~Chats: " ++ name} backRoute="chats" main side />;
};
