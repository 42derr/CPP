#!/bin/bash

# set -e

# if [ "$#" -ne 1 ]; then
#     echo "Usage: $0 NewClassName"
#     exit 1
# fi

# NEW_NAME="$1"
# OLD_NAME="Template"
# OLD_CPP="${OLD_NAME}.cpp"
# OLD_HPP="${OLD_NAME}.hpp"
# NEW_CPP="${NEW_NAME}.cpp"
# NEW_HPP="${NEW_NAME}.hpp"

# echo "Copying ${OLD_CPP} → ${NEW_CPP}..."
# cp "$OLD_CPP" "$NEW_CPP"

# echo "Copying ${OLD_HPP} → ${NEW_HPP}..."
# cp "$OLD_HPP" "$NEW_HPP"

# echo "Replacing '${OLD_NAME}' with '${NEW_NAME}' in ${NEW_CPP} and ${NEW_HPP}..."
# sed -i '' "s/${OLD_NAME}/${NEW_NAME}/g" "$NEW_CPP"
# sed -i '' "s/${OLD_NAME}/${NEW_NAME}/g" "$NEW_HPP"

# OLD_GUARD=$(echo "${OLD_NAME}_HPP" | tr '[:lower:]' '[:upper:]')
# NEW_GUARD=$(echo "${NEW_NAME}_HPP" | tr '[:lower:]' '[:upper:]')

# echo "Updating include guard: ${OLD_GUARD} → ${NEW_GUARD} in ${NEW_HPP}..."
# sed -i '' "s/${OLD_GUARD}/${NEW_GUARD}/g" "$NEW_HPP"

# echo "Replacing '${OLD_NAME}' with '${NEW_NAME}' in Makefile and main.cpp..."
# sed -i '' "s/${OLD_NAME}/${NEW_NAME}/g" Makefile
# sed -i '' "s/${OLD_NAME}/${NEW_NAME}/g" main.cpp

# echo "Deleting ${OLD_CPP} and ${OLD_HPP}..."
# rm -f "$OLD_CPP" "$OLD_HPP"

# echo "✅ Conversion complete: ${OLD_NAME} → ${NEW_NAME}"

########
#WINDOW#
########

set -e

if [ "$#" -ne 1 ]; then
    echo "Usage: $0 NewClassName"
    exit 1
fi

NEW_NAME="$1"
OLD_NAME="Template"
OLD_CPP="${OLD_NAME}.cpp"
OLD_HPP="${OLD_NAME}.hpp"
NEW_CPP="${NEW_NAME}.cpp"
NEW_HPP="${NEW_NAME}.hpp"

echo "Copying ${OLD_CPP} → ${NEW_CPP}..."
cp "$OLD_CPP" "$NEW_CPP"

echo "Copying ${OLD_HPP} → ${NEW_HPP}..."
cp "$OLD_HPP" "$NEW_HPP"

echo "Replacing '${OLD_NAME}' with '${NEW_NAME}' in ${NEW_CPP} and ${NEW_HPP}..."
sed -i "s/${OLD_NAME}/${NEW_NAME}/g" "$NEW_CPP"
sed -i "s/${OLD_NAME}/${NEW_NAME}/g" "$NEW_HPP"

OLD_GUARD=$(echo "${OLD_NAME}_HPP" | tr '[:lower:]' '[:upper:]')
NEW_GUARD=$(echo "${NEW_NAME}_HPP" | tr '[:lower:]' '[:upper:]')

echo "Updating include guard: ${OLD_GUARD} → ${NEW_GUARD} in ${NEW_HPP}..."
sed -i "s/${OLD_GUARD}/${NEW_GUARD}/g" "$NEW_HPP"

echo "Replacing '${OLD_NAME}' with '${NEW_NAME}' in Makefile and main.cpp..."
sed -i "s/${OLD_NAME}/${NEW_NAME}/g" Makefile
sed -i "s/${OLD_NAME}/${NEW_NAME}/g" main.cpp

echo "Deleting ${OLD_CPP} and ${OLD_HPP}..."
rm -f "$OLD_CPP" "$OLD_HPP"

echo "✅ Conversion complete: ${OLD_NAME} → ${NEW_NAME}"
