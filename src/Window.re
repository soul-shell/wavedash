[@react.component]
let make = (~title, ~main, ~side=?) => {
  let panes =
    switch (side) {
    | Some(children) =>
      <>
        <div className="window-panes__main"> main </div>
        <div className="window-panes__side"> children </div>
      </>
    | _ => <div className="window-panes__main"> main </div>
    };

  <div className="window">
    <div className="window-titlebar">
      <div className="window-titlebar__stripes">
        <div className="window-titlebar__stripes__title">
          {React.string(title)}
        </div>
      </div>
      <a className="window-titlebar__close-button" href="/" />
    </div>
    <div className="window-panes"> panes </div>
  </div>;
};
