type chat = {
  name: string,
  slug: string,
};

type chat_message =
  | Outbound(string)
  | Inbound(string, string);

type chat_callbacks = {
  list_chats: unit => list(chat),
  chat_messages: chat => list(chat_message),
};

module Script = {
  type azure_state =
    | FirstMessage
    | OrderSuggested
    | OrderSaved;

  [@bs.deriving jsConverter]
  type state = {azure: azure_state};

  let initialState = {azure: FirstMessage};

  let azure_messages_1 = [
    Inbound("Azure", "the ones that got banned just a year ago?"),
    Outbound("yes, those are the ones"),
    Inbound("Azure", "gimme the address and I'm on it"),
    Outbound("here you go. take care"),
  ];

  let list_chats: state => list(chat) =
    state => [{name: "Azure", slug: "Azure"}];

  let chat_messages: (state, chat) => list(chat_message) =
    (state, chat) => azure_messages_1;
};

module Storage = {
  [@bs.scope "JSON"] [@bs.val]
  external stateToJson: Script.state => string = "stringify";

  [@bs.scope "JSON"] [@bs.val]
  external stateFromJson: string => Script.state = "parse";

  let load = () =>
    "state"
    ->Dom.Storage.(getItem(localStorage))
    ->Belt.Option.mapWithDefault(Script.initialState, stateFromJson);

  let save = s =>
    s |> stateToJson |> Dom.Storage.(setItem("state", _, localStorage));
};
