[@bs.val] external document: Js.t({..}) = "document";

let container = document##createElement("main");
let () = document##body##appendChild(container);

ReactDOMRe.render(<Chats />, container);
