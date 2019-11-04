[@bs.deriving jsConverter]
type chat =
  | Azure
  | Meli;

let chat_name = chat =>
  switch (chat) {
  | Azure => "Azure"
  | Meli => "Meli"
  };

type chat_msg = {
  text: string,
  from: option(string),
};

module WeekScript1 = {
  type t = {chat_msg_idx: int};

  let azure_messages = [|
    {text: "the ones that got banned just a year ago?", from: Some("Azure")},
    {text: "yes, those are the ones", from: None},
    {text: "gimme the address and I'm on it", from: Some("Azure")},
    {text: "here you go. take care", from: None},
  |];

  let chats = _ => [Azure];

  let advance_chat = (state, _chat) =>
    if (state.chat_msg_idx < Js.Array.length(azure_messages)) {
      let new_state = {chat_msg_idx: state.chat_msg_idx + 1};
      let msg = azure_messages[state.chat_msg_idx];
      (new_state, Some(msg));
    } else {
      (state, None);
    };
};

[@bs.deriving jsConverter]
type state =
  | Intro
  | Week1(WeekScript1.t);

let defaultState = Intro;

module Storage = {
  [@bs.scope "JSON"] [@bs.val]
  external stateToJson: state => string = "stringify";

  [@bs.scope "JSON"] [@bs.val]
  external stateFromJson: string => state = "parse";

  let load = () =>
    "state"
    ->Dom.Storage.(getItem(localStorage))
    ->Belt.Option.mapWithDefault(defaultState, stateFromJson);

  let save = s =>
    s |> stateToJson |> Dom.Storage.(setItem("state", _, localStorage));
};
