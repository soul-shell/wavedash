[@bs.val] external document: Js.t({..}) = "document";

let container = document##createElement("main");
let () = document##body##appendChild(container);

let state = State.Storage.load();

ReactDOMRe.render(<Router />, container);
