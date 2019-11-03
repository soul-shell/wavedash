type message = {
  text: string,
  own: bool,
};

[@react.component]
let make = (~name, ~asset) => {
  let chats =
    [|
      {text: "the ones that got banned just a year ago?", own: false},
      {text: "yes, those are the ones", own: true},
      {text: "gimme the address and I'm on it", own: false},
      {text: "here you go. take care", own: true},
    |]
    |> Js.Array.map(m => {
         let className =
           m.own ? "chat-message" : "chat-message chat-message--incoming";
         <div className> {React.string(m.text)} </div>;
       });

  let main = <div className="chat"> {React.array(chats)} </div>;
  let side = <img className="chat-sprite" src={asset("azure.png")} />;

  <Window title={"~Chats: " ++ name} backRoute="chats" main side />;
};
