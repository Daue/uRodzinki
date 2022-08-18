.pragma library

function dateFromString(text) {

    var dateComponents = text.split('-');

    return new Date(
                  dateComponents[ 0 ]
                , dateComponents[ 1 ] - 1
                , dateComponents[ 2 ]
                );
}

function formatDate(date)
{
    const monthNames = [
        "Styczeń"
      , "Luty"
      , "Marzec"
      , "Kwiecień"
      , "Maj"
      , "Czerwiec"
      , "Lipiec"
      , "Sierpień"
      , "Wrzesień"
      , "Październik"
      , "Listopad"
      , "Grudzień"
      ];

    var day = date.getDate();
    var month = monthNames[ date.getMonth() ];
    var year = date.getFullYear();
    var howOld = calculatePersonYears(date);

    return day + " " + month + " (" + year + ")  [" + howOld + "]";
}

function calculatePersonYears(date)
{
    var now = new Date();

    var diffrent = now.getFullYear() - date.getFullYear();

    if ( now.getMonth() < date.getMonth() )
        diffrent -= 1;
    else if ( now.getMonth() === date.getMonth() && now.getDate() < date.getDate() )
        diffrent -= 1;

    return diffrent;
}
