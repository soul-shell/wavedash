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

  <div>
    <div className="window">
      <div className="window-titlebar">
        <div className="window-titlebar__stripes">
          <div className="window-titlebar__stripes__title">
            {React.string("~Chats: " ++ name)}
          </div>
        </div>
        <a className="window-titlebar__close-button" href="/" />
      </div>
      <div className="window-content">
        <div className="chat"> {React.array(chats)} </div>
      </div>
    </div>
  </div>;
};
