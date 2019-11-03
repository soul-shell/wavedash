[@react.component]
let make = (~title, ~main, ~side=?, ~backRoute: option(string)=?) => {
  let backButton =
    switch (backRoute) {
    | Some(url) => <RouterLink className="window-titlebar__close-button" url />
    | _ => React.null
    };
  let sidePane =
    switch (side) {
    | Some(children) => <div className="window-panes__side"> children </div>
    | _ => React.null
    };

  <div className="window">
    <div className="window-titlebar">
      <div className="window-titlebar__stripes">
        <div className="window-titlebar__stripes__title">
          {React.string(title)}
        </div>
      </div>
      backButton
    </div>
    <div className="window-panes">
      <div className="window-panes__main"> main </div>
      sidePane
    </div>
  </div>;
};
