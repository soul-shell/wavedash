type state = {count: int};

type action =
  | Increment
  | Decrement;

let initialState = {count: 0};

let reducer = (state, action) => {
  switch (action) {
  | Increment => {count: state.count + 1}
  | Decrement => {count: state.count - 1}
  };
};

[@react.component]
let make = () => {
  let (state, dispatch) = React.useReducer(reducer, initialState);

  <div
    style={ReactDOMRe.Style.make(
      ~display="flex",
      ~alignItems="center",
      ~justifyContent="space-between",
      (),
    )}>
    <div>
      {React.string("Count: ")}
      {React.string(string_of_int(state.count))}
    </div>
    <div>
      <button onClick={_event => dispatch(Decrement)}>
        {React.string("-")}
      </button>
      <button onClick={_event => dispatch(Increment)}>
        {React.string("+")}
      </button>
    </div>
  </div>;
};
