// Entry point

[@bs.val] external document: Js.t({..}) = "document";

let makeContainer = text => {
  let container = document##createElement("div");
  container##className #= "container";

  let title = document##createElement("div");
  title##innerText #= text;

  let content = document##createElement("div");

  let () = container##appendChild(title);
  let () = container##appendChild(content);
  let () = document##body##appendChild(container);

  content;
};

// All 4 examples.
ReactDOMRe.render(
  <Greeting> {React.string("Hello!")} </Greeting>,
  makeContainer("Blinking Greeting"),
);

ReactDOMRe.render(<Reducer />, makeContainer("Reducer From ReactJS Docs"));
