type message = {
  text: string,
  own: bool,
};

[@react.component]
let make = (~name) => {
  let chats =
    [|
      {text: "the ones that got banned just a year ago?", own: false},
      {text: "yes, those are the ones", own: true},
      {text: "gimme the address and I'm on it", own: false},
      {text: "here you go. take care", own: true},
    |]
    |> Js.Array.map(m => {
         let className =
           m.own ? "chat__message" : "chat__message chat__message--incoming";
         <div className> {React.string(m.text)} </div>;
       });

  let main = <div className="chat"> {React.array(chats)} </div>;
  let side = <div> {React.string("h")} </div>;

  <Window title={"~Chats: " ++ name} main side />;
};
