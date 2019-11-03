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
      <div className="top-bar-wave top-bar-dropdown">
        <span className="top-bar-wave__glyph"> {React.string("~")} </span>
        <div className="top-bar-dropdown__content">
          <a className="top-bar-link" href="#"> {React.string("About Wavedash")} </a>
        </div>
      </div>
      <div className="top-bar-dropdown">
        {React.string("File")}
        <div className="top-bar-dropdown__content">
          <a className="top-bar-link" href="#"> {React.string("Close window")} </a>
          <a className="top-bar-link" href="#"> {React.string("Show clipboard")} </a>
        </div>
      </div>
    </header>
    <section className="desktop"> window </section>
  </>;
};
