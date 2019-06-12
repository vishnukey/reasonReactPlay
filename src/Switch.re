let lightBlue = "#AAAAFF";
let darkBlue = "#5555FF";

let mainStyle =
  ReactDOMRe.Style.make(
    ~padding="3px",
    //~margin="1px",
    ~borderStyle="solid",
    ~borderWidth="1px",
    (),
  );

[@react.component]
let make = (~name, ~onClick) => {
  let (isHover, setHover) =
    React.useReducer((_, newState) => newState, false);
  let onMouseEnter = _ => setHover(true);
  let onMouseLeave = _ => setHover(false);

  let style =
    (
      isHover
        ? ReactDOMRe.Style.make(~backgroundColor=darkBlue, ())
        : ReactDOMRe.Style.make(~backgroundColor=lightBlue, ())
    )
    |> ReactDOMRe.Style.combine(mainStyle);
  <div style onMouseEnter onMouseLeave onClick>
    {name |> ReasonReact.string}
  </div>;
};
