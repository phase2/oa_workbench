; Open Atrium Workbench Makefile

api = 2
core = 7.x

projects[workbench][version] = 1.2
projects[workbench][subdir] = contrib

projects[workbench_moderation][version] = 1.x-dev
projects[workbench_moderation][subdir] = contrib
projects[workbench_moderation][download][type] = git
projects[workbench_moderation][download][branch] = 7.x-1.x
projects[workbench_moderation][patch][1285090] = https://www.drupal.org/files/playnicewithpanels-1285090-22.patch

; TODO: Update to official Drupal.org Git repo and select a specific version.
projects[workbench_moderation_profile][type] = module
projects[workbench_moderation_profile][subdir] = contrib
projects[workbench_moderation_profile][download][url] = http://git.drupal.org/sandbox/srjosh/2172925.git
projects[workbench_moderation_profile][download][type] = git
projects[workbench_moderation_profile][download][branch] = 7.x-1.x
