[@react.component]
let make = () => {
  <header className="top-bar">
    <div className="top-bar-wave top-bar-menu">
      <span className="top-bar-wave__glyph"> {React.string("~")} </span>
      <div className="top-bar-menu__content">
        <a className="top-bar-link" href="#">
          {React.string("About Wavedash")}
        </a>
        <hr className="top-bar-menu-sep" />
        <RouterLink className="top-bar-link" url="chats">
          {React.string("Chats")}
        </RouterLink>
      </div>
    </div>
    <div className="top-bar-menu">
      {React.string("File")}
      <div className="top-bar-menu__content">
        <a className="top-bar-link" href="#">
          {React.string("Close window")}
        </a>
        <a className="top-bar-link" href="#">
          {React.string("Show clipboard")}
        </a>
      </div>
    </div>
  </header>;
};
