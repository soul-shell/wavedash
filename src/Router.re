[@react.component]
let make = () => {
  let production: bool = [%bs.raw {| process.env.NODE_ENV === 'production' |}];
  let asset = name => production ? "/" ++ name : "/dist/" ++ name;

  let url = ReasonReactRouter.useUrl();
  let path = url.hash |> Js.String.split("/") |> Array.to_list;

  let window =
    switch (path) {
    | ["chats"] => <Chats />
    | ["chats", name] => <Chat name asset />
    | _ => <div> {React.string("?")} </div>
    };
  ();

  <>
    <header className="top-bar">
      <a className="top-bar-wave" href="#">
        <span className="top-bar-wave__glyph"> {React.string("~")} </span>
      </a>
      <a className="top-bar-link" href="#"> {React.string("File")} </a>
    </header>
    <section className="desktop"> window </section>
  </>;
};
