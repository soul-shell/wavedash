[@react.component]
let make = (~className, ~url, ~children) => {
  let onClick = e => {
    ReactEvent.Mouse.preventDefault(e);
    ReasonReactRouter.push("#" ++ url);
  };
  <a className href="#" onClick> children </a>;
};
