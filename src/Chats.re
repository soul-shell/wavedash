[@react.component]
let make = () => {
  <div>
    <div className="window">
      <div className="window-titlebar">
        <div className="window-titlebar__stripes">
          <div className="window-titlebar__stripes__title">
            {React.string("Chats")}
          </div>
        </div>
        <a className="window-titlebar__close-button" href="/" />
      </div>
      <div className="window-content">
        <a className="item-row" href="#"> {React.string("Azure")} </a>
      </div>
    </div>
  </div>;
};
