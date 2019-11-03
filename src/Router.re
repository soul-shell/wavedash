[@react.component]
let make = () => {
  let production: bool = [%bs.raw {| process.env.NODE_ENV === 'production' |}];
  let asset = (name) => production ? "/" ++ name : "/dist/" ++ name;

  let url = ReasonReactRouter.useUrl();
  let path = url.hash |> Js.String.split("/") |> Array.to_list;

  switch (path) {
  | ["chats"] => <Chats />
  | ["chats", name] => <Chat name asset />
  | _ => <div> {React.string("?")} </div>
  };
};
