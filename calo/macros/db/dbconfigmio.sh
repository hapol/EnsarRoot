# add for MySql libs
# MAc OSx
# export DYLD_LIBRARY_PATH=$DYLD_LIBRARY_PATH:/usr/local/mysql/lib
# Linux

# Log File 
# -- If the string is NULL the default file "fairdbinfo.log"
# -- will be created in the working directory 
export FAIRDB_LOGFILE_DB=""



if [ $1 = "local_mysql" ]
then
# Local MySQL server
export FAIRDB_TSQL_URL="mysql://localhost/r3b"
export FAIRDB_TSQL_USER="scott"
export FAIRDB_TSQL_PSWD="tiger"
fi

if [ $1 = "local_pgsql" ]
then
# Local PgSQL server
export PATH=$PATH:$HOME/Work/postgresql/bin
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$HOME/Work/postgresql/lib
export PGSQL=$HOME/Work/postgresql
export FAIRDB_TSQL_URL="pgsql://localhost:5432/r3b"
export FAIRDB_TSQL_USER="ygonroz"
export FAIRDB_TSQL_PSWD="44849937USC"
fi


if [ $1  = "local_sqlite" ]
then
# SQLite
export FAIRDB_TSQL_URL="sqlite://test.sqlite"
export FAIRDB_TSQL_USER="test"
export FAIRDB_TSQL_PSWD="test"
fi

echo $1 " session configured as: "
set | grep TSQL*
