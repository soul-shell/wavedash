[@react.component]
let make = () => {
  let url = ReasonReactRouter.useUrl();
  let path = url.hash |> Js.String.split("/") |> Array.to_list;

  switch (path) {
  | ["chats"] => <Chats />
  | ["chats", name] => <Chat name />
  | _ => <div> {React.string("?")} </div>
  };
};
