--spool C:\Users\gherg\Desktop\filename.sql
--select* from masini
--/
--spool off

set serveroutput on;

create or replace procedure my_function (table_name in varchar2) as
sqlString varchar2(100);
v_cursor BINARY_INTEGER;
v_ReturnCode BINARY_INTEGER;
sqlString2 varchar2(100);
v_cursor2 BINARY_INTEGER;
v_ReturnCode2 BINARY_INTEGER;
rowNr number(30);
sqlString3 varchar2(100);
v_cursor3 BINARY_INTEGER;
v_ReturnCode3 BINARY_INTEGER;
begin
--obtain rowNr

sqlString3 := 'select count(nr_matricol) into'|| rowNr|| ' from ' ||table_name;
select* from user_tables;
v_cursor3 := DBMS_SQL.OPEN_CURSOR;
DBMS_SQL.PARSE(v_cursor3, sqlString3, DBMS_SQL.NATIVE);
v_ReturnCode3 := DBMS_SQL.EXECUTE(v_cursor3);
DBMS_SQL.CLOSE_CURSOR(v_cursor3);
--dbms_output.put_line('numarul de linii este'||rowNr);
--drop
--   sqlString := 'DROP TABLE '|| table_name;
--   v_cursor := DBMS_SQL.OPEN_CURSOR;
--   DBMS_SQL.PARSE(v_cursor, sqlString, DBMS_SQL.NATIVE);
--   v_ReturnCode := DBMS_SQL.EXECUTE(v_cursor);
--   DBMS_SQL.CLOSE_CURSOR(v_cursor); 
--create
--sqlString2 := 'create table '||table_name||' as (select* from studenti)';
--    v_cursor2 := DBMS_SQL.OPEN_CURSOR;
--   DBMS_SQL.PARSE(v_cursor2, sqlString2, DBMS_SQL.NATIVE);
--   v_ReturnCode2 := DBMS_SQL.EXECUTE(v_cursor2);
--   DBMS_SQL.CLOSE_CURSOR(v_cursor2); 
end my_function;
/

BEGIN
my_function('erasmus');
END;
