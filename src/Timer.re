type state =
  | Start
  | Stop;

let timerStyle =
  ReactDOMRe.Style.make(
    ~fontWeight="bold",
    ~fontFamily="sans-serif",
    ~fontSize="24px",
    (),
  );

let formatTime = (time: int) => {
  let minutes = time / 60;
  let seconds = time mod 60;

  (minutes < 10 ? "0" : "")
  ++ string_of_int(minutes)
  ++ ":"
  ++ (seconds < 10 ? "0" : "")
  ++ string_of_int(seconds);
};

[@react.component]
let make = (~time: int) => {
  let initTime = _ => time * 60;

  let (timeLeft, setTime) = React.useState(initTime);
  let (state, setState) =
    React.useReducer((_, newState) => newState, Start);

  React.useEffect(() => {
    let timeout =
      switch (state) {
      | Start =>
        Some(
          Js.Global.setTimeout(() => setTime(pastTime => pastTime - 1), 1000),
        )
      | Stop => None
      };
    Some(
      () =>
        switch (timeout) {
        | Some(id) => Js.Global.clearTimeout(id)
        | None => ()
        },
    );
  });

  let start = _ => Start |> setState;
  let stop = _ => Stop |> setState;
  let reset = _ => initTime |> setTime;

  <div>
    <div style=timerStyle>
      {timeLeft |> formatTime |> ReasonReact.string}
    </div>
    <ul style=Switcher.listStyle>
      <li key="timer-start" style=Switcher.itemStyle>
        <TimerButton
          darkColour="#00CC00"
          colour="#44FF44"
          name="Start"
          onClick=start
        />
      </li>
      <li key="timer-stop" style=Switcher.itemStyle>
        <TimerButton
          darkColour="#CC0000"
          colour="#FF4444"
          name="Stop"
          onClick=stop
        />
      </li>
      <li key="timer-reset" style=Switcher.itemStyle>
        <TimerButton
          colour="#FFFFFF"
          darkColour="#CCCCCC"
          name="Reset"
          onClick=reset
        />
      </li>
    </ul>
  </div>;
};
