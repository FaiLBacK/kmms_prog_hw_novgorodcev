CPP_FILES="menu_functions.cpp menu_items.cpp main.cpp"
APP=math
DIR=bin

mkdir -p $DIR

if [ -f /$DIR/$APP ]; then rm $DIR/$APP
fi

g++ $CPP_FILES -o $DIR/$APP

cd $DIR && ./$APP