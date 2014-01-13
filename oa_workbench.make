; Open Atrium Workbench Makefile

api = 2
core = 7.x

projects[workbench][version] = 1.2
projects[workbench][subdir] = contrib

projects[workbench_moderation][version] = 1.3
projects[workbench_moderation][subdir] = contrib

; TODO: Update to Drupal.org Git repo and select a specific version.
projects[workbench_moderation_profile][type] = module
projects[workbench_moderation_profile][subdir] = contrib
projects[workbench_moderation_profile][download][url] = git@bitbucket.org:phase2tech/workbench_moderation_profile.git
projects[workbench_moderation_profile][download][type] = git
;projects[workbench_moderation_profile][download][revision] = XXXXXXX
projects[workbench_moderation_profile][download][branch] = master

