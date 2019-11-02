[@react.component]
let make = () => {
  <div>
    <div className="window">
      <div className="window-titlebar">
        <div className="window-titlebar__stripes">
          <div className="window-titlebar__stripes__title">
            {React.string("shell")}
          </div>
        </div>
      </div>
      <div className="window-content">
        <a className="file-row" href="connect.html">
          {React.string("Connect")}
          <span className="file-row__type"> {React.string("app")} </span>
        </a>
        <a className="file-row" href="notes.html">
          {React.string("Notes to Administrator")}
          <span className="file-row__type"> {React.string("document")} </span>
        </a>
      </div>
    </div>
  </div>;
};
