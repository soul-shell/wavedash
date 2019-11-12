[@react.component]
let make = (~state) => {
  let production: bool = [%bs.raw {| process.env.NODE_ENV === 'production' |}];
  let asset = name => production ? "/" ++ name : "/dist/" ++ name;

  let url = ReasonReactRouter.useUrl();
  let path = url.hash |> Js.String.split("/") |> Array.to_list;

  let window =
    switch (path) {
    | ["chats"] => <Chats />
    | ["chats", name] => <Chat name asset state />
    | _ => <div> {React.string("?")} </div>
    };
  ();

  <> <TopBar /> <section className="desktop"> window </section> </>;
};
