 ----------------------------------------------------------
 |    LEM-IN    General Commands Manual   ./lem-in man    |
 ----------------------------------------------------------
 |NAME                                                    |
 |        lem-in                                          |
 |                                                        |
 |SYNOPSIS                                                |
 |        ./lem-in < [lem-in file] (optional flag)        |
 |                                                        |
 |DESCRIPTION                                             |
 |        The goal of the lem-in project is to find the   |
 |        paths between rooms.                            |
 |        You sent some ants from point A to point B.     |
 |        The recup stop if a line don't match required   |
 |        criteras, solving start with previous infos     |
 |        File format:                                    |
 |                  1. number of ants                     |
 |                  2. room definitions                   |
 |                  3. tube definitions                   |
 |                                                        |
 |        first line     nb of ants                       |
 |        # comment      You can put comments with '#'    |
 |        ##start        next room = start point          |
 |        ##end          next room = end point            |
 |        max line len   LEN_LINE = 80                    |
 |        max nb room    ROOMLEN = 2000                   |
 |        room coord     0 <= x < +2147483647             |
 |        only ONE room per number and coord              |
 ----------------------------------------------------------

 ----------------------------------------------------------
 |FLAGS                                                   |
 |        'basics'        Display basic recup infos       |
 |        'matrix'        Display the Cost Matrix         |
 |        'print'         display recup & cost matrix     |
 |        'roominfo'      Rooms weight, degree, dispo     |
 |        'man'           display user manual             |
 |        'errmode'       display detailed errors         |
 |        'noorder'       Room and tube can be defined    |
 |                        without order.                  |
 |        'bestpath'      disp best path START --> END    |
 |        'color'         Display color when ouput        |
 |                                                        |
 |'redefine_startend{A}{B}'   Redefinition of start & end |
 |'redefine_bestpath{A}{B}'   Redefinition of bestpath    |
 ----------------------------------------------------------
