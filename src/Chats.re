[@react.component]
let make = () => {
  <div>
    <div className="window">
      <div className="window-titlebar">
        <div className="window-titlebar__stripes">
          <div className="window-titlebar__stripes__title">
            {React.string("~Chats")}
          </div>
        </div>
        <a className="window-titlebar__close-button" href="/" />
      </div>
      <div className="window-content">
        <RouterLink className="item-row" url="chats/azure">
          {React.string("Azure")}
        </RouterLink>
      </div>
    </div>
  </div>;
};
