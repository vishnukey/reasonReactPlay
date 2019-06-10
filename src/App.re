module Post{
        let content =
                "Some big amount of conent here " ++
                "that doesn't really say anything. " ++
                "It is here nonetheless, though";

        let style = ReactDOMRe.Style.make(
                ~borderStyle   = "solid",
                ~borderWidth   = "1px",
                ~paddingLeft   = "3px",
                ~paddingRight  = "3px",
                ~paddingBottom = "1px",
                ~marginBottom  = "2px",
                ()
        );

        [@react.component]
        let make = (~id:int, ~title:string) => {
                <div className="post" id={string_of_int(id)} style={style}>
                        <span>
                                <strong>{ReasonReact.string("#"++string_of_int(id))}</strong>
                                <center>
                                        <h2>{ReasonReact.string(title)}</h2>
                                </center>
                        </span>
                        <div className="post-content">
                                {ReasonReact.string(content)}
                        </div>
                </div>
        };
};


[@react.component]
let make = (~header) => {
        <div>
                <h1>
                        <center>
                                {ReasonReact.string(header)}
                        </center>
                </h1>
                <hr />
                {ReasonReact.array(
                        Array.init(8, i =>
                                <Post
                                        key=string_of_int(i)
                                        id=i
                                        title="Some Title" />))}
        </div>
};
