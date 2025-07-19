#!/bin/bash

# Set starting date and today's date
start_date="2024-11-01"
current_date="$start_date"
today=$(date +"%Y-%m-%d")

# Convert date to epoch (for comparison)
date_to_epoch() {
    date -j -f "%Y-%m-%d" "$1" +"%s"
}

# Add N days to a date string (macOS-compatible)
add_days() {
    date -j -f "%Y-%m-%d" -v+"$1"d "$2" +"%Y-%m-%d"
}

# Only include real files, skip commit.sh and .git files
files=$(find . -type f -not -path '*/\.git/*' -not -name 'commit.sh')

for file in $files; do
    # Skip if file doesn't exist
    if [ ! -f "$file" ]; then
        continue
    fi

    # Stop if current_date > today
    if [ "$(date_to_epoch "$current_date")" -gt "$(date_to_epoch "$today")" ]; then
        echo "⛔ Reached today's date ($today), stopping commits."
        break
    fi

    # Stage the file
    git add "$file"

    # Commit message
    msg="✅ Committed $file"

    # Generate random time (08:00 to 17:59)
    hour=$((RANDOM % 10 + 8))
    min=$((RANDOM % 60))
    sec=$((RANDOM % 60))
    commit_date="$current_date $hour:$min:$sec"

    # Set fake dates and commit
    GIT_AUTHOR_DATE="$commit_date +0530" GIT_COMMITTER_DATE="$commit_date +0530" git commit -m "$msg"
    echo "$msg at $commit_date"

    # Increment current date by 2–4 random days
    rand_days=$((RANDOM % 3 + 2))
    current_date=$(add_days $rand_days "$current_date")
done

# Push all commits
git push origin main
echo "✅ All commits pushed to origin/main."
