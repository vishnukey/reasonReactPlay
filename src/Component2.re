/* State declaration */
type state = {
  count: int,
  show: bool,
};

/* Action declaration */
type action =
  | Click
  | Toggle;

 let styler = ReactDOMRe.Style.make;

[@react.component]
let make = (~greeting) => {
  let (state, dispatch) = React.useReducer((state, action) =>
  switch (action) {
  | Click => {...state, count: state.count + 1}
  | Toggle => {...state, show: ! state.show}
  }, {count: 0, show: true});

  let message =
    "You've clicked this " ++ string_of_int(state.count) ++ " times(s)";
  <div style=styler(~backgroundColor="red", ())>
    <button onClick={_event => dispatch(Click)}>
      {ReasonReact.string(message)}
    </button>
    <button onClick={_event => dispatch(Toggle)}>
      {ReasonReact.string("Toggle greeting")}
    </button>
    {state.show ? ReasonReact.string(greeting) : ReasonReact.null}
  </div>;
};
