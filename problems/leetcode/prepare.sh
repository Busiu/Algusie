#!/bin/bash

# Check if all arguments are provided
if [ "$#" -ne 3 ]; then
    echo "Usage: ./prepare_contest.sh <type: w/b> <contest_num> <start_task_num>"
    exit 1
fi

TYPE_INPUT=$1
CONTEST_NUM=$2
START_TASK=$3

# 1. Determine contest type and URL slug
if [ "$TYPE_INPUT" == "w" ]; then
    TYPE_NAME="weekly"
    FOLDER_PREFIX="weekly"
elif [ "$TYPE_INPUT" == "b" ]; then
    TYPE_NAME="biweekly"
    FOLDER_PREFIX="biweekly"
else
    echo "Error: Use 'w' for weekly or 'b' for biweekly."
    exit 1
fi

# 2. Set up variables
CONTEST_URL="https://leetcode.com/contest/${TYPE_NAME}-contest-${CONTEST_NUM}/"
CURRENT_DATE=$(date +%Y-%m-%d)
FOLDER_NAME="${FOLDER_PREFIX}_${CONTEST_NUM}"
TEMPLATE_FILE="leetcode_template.cpp"

# Check if template exists
if [ ! -f "$TEMPLATE_FILE" ]; then
    echo "Error: $TEMPLATE_FILE not found in current directory."
    exit 1
fi

# 3. Create the contest directory
mkdir -p "$FOLDER_NAME"

# 4. Generate the 4 files
for i in {0..3}
do
    TASK_NUM=$((START_TASK + i))
    TARGET_FILE="${FOLDER_NAME}/${TASK_NUM}.cpp"
    
    # Copy template to new file
    cp "$TEMPLATE_FILE" "$TARGET_FILE"
    
    # Replace placeholders
    sed -i "s|// Source - ???|// Source - ${CONTEST_URL}|g" "$TARGET_FILE"
    sed -i "s|// Date - ???|// Date - ${CURRENT_DATE}|g" "$TARGET_FILE"
done

echo "Successfully created folder: $FOLDER_NAME with 4 files."