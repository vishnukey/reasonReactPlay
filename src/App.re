[@react.component]
let make = (~header) => {
        <div>
                <h1>
                        <center>
                                {ReasonReact.string(header)}
                        </center>
                </h1>
                <hr />
        </div>
};
